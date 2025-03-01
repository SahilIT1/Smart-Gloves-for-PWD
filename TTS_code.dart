import 'dart:typed_data'; // For Uint8List
import 'package:flutter/material.dart';
import 'package:flutter_tts/flutter_tts.dart';
import 'package:flutter_bluetooth_serial/flutter_bluetooth_serial.dart';
import 'package:permission_handler/permission_handler.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);
  
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Smart Glove App',
      debugShowCheckedModeBanner: false, // Remove debug watermark
      theme: ThemeData.dark(),
      home: const HomeScreen(),
    );
  }
}

class HomeScreen extends StatefulWidget {
  const HomeScreen({Key? key}) : super(key: key);
  
  @override
  State<HomeScreen> createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  final FlutterTts _flutterTts = FlutterTts();
  BluetoothState _bluetoothState = BluetoothState.UNKNOWN;
  BluetoothConnection? _connection;
  bool _isConnecting = false;
  bool _isConnected = false;
  String _gloveOutput = "Glove output will appear here";
  
  // Buffer for accumulating incoming data
  String _buffer = "";
  
  // Request necessary Bluetooth permissions (for Android 12+)
  Future<void> requestBluetoothPermissions() async {
    if (await Permission.bluetoothConnect.isDenied) {
      await Permission.bluetoothConnect.request();
    }
    if (await Permission.bluetoothScan.isDenied) {
      await Permission.bluetoothScan.request();
    }
  }
  
  @override
  void initState() {
    super.initState();
    requestBluetoothPermissions();
    
    // Listen for Bluetooth state changes.
    FlutterBluetoothSerial.instance.state.then((state) {
      setState(() {
        _bluetoothState = state;
      });
    });
    FlutterBluetoothSerial.instance.onStateChanged().listen((BluetoothState state) {
      setState(() {
        _bluetoothState = state;
      });
    });
  }
  
  @override
  void dispose() {
    _connection?.dispose();
    _connection = null;
    _flutterTts.stop();
    super.dispose();
  }
  
  // Start listening for incoming data, buffering until a newline is received.
  void _startListening(BluetoothConnection connection) {
    connection.input?.listen((Uint8List data) {
      _buffer += String.fromCharCodes(data);
      
      // Process messages split by newline.
      if (_buffer.contains('\n')) {
        List<String> messages = _buffer.split('\n');
        for (int i = 0; i < messages.length - 1; i++) {
          String completeMessage = messages[i].trim();
          if (completeMessage.isNotEmpty) {
            setState(() {
              _gloveOutput = completeMessage;
            });
          }
        }
        // Keep any remaining partial message.
        _buffer = messages.last;
      }
    }).onDone(() {
      setState(() {
        _isConnected = false;
        _gloveOutput = "Disconnected from glove.";
      });
    });
  }
  
  // Show a dialog for the user to select a bonded device.
  Future<BluetoothDevice?> _selectBondedDevice(List<BluetoothDevice> devices) async {
    return showDialog<BluetoothDevice>(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: const Text('Select a Device'),
          content: Container(
            width: double.maxFinite,
            height: 300,
            child: ListView.builder(
              itemCount: devices.length,
              itemBuilder: (context, index) {
                BluetoothDevice device = devices[index];
                return ListTile(
                  title: Text(device.name ?? device.address),
                  onTap: () {
                    Navigator.of(context).pop(device);
                  },
                );
              },
            ),
          ),
        );
      },
    );
  }
  
  // Connect to a selected Bluetooth device.
  Future<void> _connectToGlove() async {
    await requestBluetoothPermissions();
    
    if (_bluetoothState == BluetoothState.STATE_OFF) {
      setState(() {
        _gloveOutput = "Please enable Bluetooth first!";
      });
      return;
    }
    
    setState(() {
      _isConnecting = true;
      _gloveOutput = "Scanning for devices...";
    });
    
    try {
      // Retrieve the list of paired (bonded) devices.
      List<BluetoothDevice> bondedDevices =
          await FlutterBluetoothSerial.instance.getBondedDevices();
      print("Bonded devices: ${bondedDevices.map((d) => d.name)}");
      
      if (bondedDevices.isEmpty) {
        setState(() {
          _gloveOutput = "No paired devices found. Please pair your device first.";
        });
        return;
      }
      
      // Let the user select a device from a dialog.
      BluetoothDevice? selectedDevice = await _selectBondedDevice(bondedDevices);
      if (selectedDevice == null) {
        setState(() {
          _gloveOutput = "No device selected.";
        });
        return;
      }
      
      setState(() {
        _gloveOutput = "Connecting to ${selectedDevice.name}...";
      });
      
      // Connect to the selected device.
      BluetoothConnection connection =
          await BluetoothConnection.toAddress(selectedDevice.address);
      setState(() {
        _connection = connection;
        _isConnected = true;
        _gloveOutput = "Connected to ${selectedDevice.name}! Waiting for data...";
      });
      
      // Start listening for incoming data.
      _startListening(connection);
      
    } catch (e) {
      setState(() {
        _gloveOutput = "Connection error: $e";
      });
    } finally {
      setState(() {
        _isConnecting = false;
      });
    }
  }
  
  // Disconnect from the connected device.
  Future<void> _disconnect() async {
    if (_isConnected && _connection != null) {
      await _connection!.close();
      setState(() {
        _isConnected = false;
        _gloveOutput = "Disconnected from glove.";
      });
    }
  }
  
  // Toggle connection state: if connected, disconnect; if disconnected, connect.
  Future<void> _toggleConnection() async {
    if (_isConnected) {
      await _disconnect();
    } else {
      await _connectToGlove();
    }
  }
  
  // Speak the current glove output using English TTS.
  Future<void> _speakEnglish() async {
    await _flutterTts.setLanguage('en-US');
    await _flutterTts.speak(_gloveOutput);
  }
  
  @override
  Widget build(BuildContext context) {
    // Determine button appearance based on connection state.
    final Color buttonColor = _isConnected ? Colors.red : Colors.green;
    final String buttonText = _isConnecting
        ? 'Connecting...'
        : _isConnected ? 'Disconnect' : 'Connect';
    
    return Scaffold(
      body: SafeArea(
        child: Container(
          color: Colors.black,
          padding: const EdgeInsets.all(16.0),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              // Toggle button for Connect/Disconnect
              ElevatedButton(
                style: ElevatedButton.styleFrom(primary: buttonColor),
                onPressed: _isConnecting ? null : _toggleConnection,
                child: Text(
                  buttonText,
                  style: const TextStyle(color: Colors.black, fontSize: 18),
                ),
              ),
              const SizedBox(height: 20),
              // Display for glove output
              Container(
                width: double.infinity,
                height: 50,
                color: Colors.white,
                child: Center(
                  child: Text(
                    _gloveOutput,
                    textAlign: TextAlign.center,
                    style: const TextStyle(color: Colors.black, fontSize: 16),
                  ),
                ),
              ),
              const SizedBox(height: 20),
              // English TTS button
              ElevatedButton(
                onPressed: _speakEnglish,
                child: const Text('English'),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
