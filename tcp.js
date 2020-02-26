const net = require('net');
const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');
const path = require('path');

SerPort = new SerialPort('/dev/ttyUSB0', {
    baudRate: 9600,
    parity: "none"
}, function (err) {
    if (err) {
        console.log('serial port Error');
    }
});

var args = process.argv
var client = new net.Socket();

var SimulatorDeviceId = "amzn1.ask.device.AHNO6NEHBF6KQ7WJZQQ7BAGXYXYM4GFBVLR5QJHIDE6J7BYKQTYHJ5AAHTHGPTH5THNIWVNO64LPV5L74RXPBLGIIEY7UFUWHPVPIPP7P76YK52NQ34UEKFHSZ3XON7RHQXQ2LKXTJEWLHYDRXMZ73A2GCYA";
var PhoneDeviceId = "amzn1.ask.device.AHNO6NEHBF6KQ7WJZQQ7BAGXYXYI2L5EWAD7INIM5LSMKZGCHFQBNFGITPURWABHYNWDY646NU36NGNI6MNLIU6RNXIHT64MVSZB4JVRY2IZISHJDZWYEP3IM35PJ23WZZQI5JW22TWDCT7VIKUZKPXMQQ45GEC7TZWQU7J3J5IYTVRN37FSM"

var host = 'creepyfuck.tech'
if (args.includes('dev')) {
    host = 'localhost';
}

client.connect(1337, host, function () {
    console.log('Connected');
    //client.write('CONNECT');
});

client.on('data', function (data) {
    if (data + "" == "ID")
        client.write("AB")

    console.log(data + "#")

    console.log((data + "").substring(0, (data + "").length - 1) + "$")

    switch ((data + "").substring(0, (data + "").length - 1)) {
        case "play":
            SerPort.write("NEC:551489010$32");
            break;
        case "pause":
            SerPort.write("NEC:551489010$32");

            break;
        case "mute":
            SerPort.write("NEC:551522415$32");
            break;

        case "volume down":
            SerPort.write("NEC:551534655$32");
            break;

        case "volume up":
            SerPort.write("NEC:551502015$32");
            break;

        case "volume down 5":
            SerPort.write("NEC:551534655$32");
            setTimeout(() => {SerPort.write("NEC:551534655$32\n");}, 500);
            setTimeout(() => {SerPort.write("NEC:551534655$32\n");}, 200);
            setTimeout(() => {SerPort.write("NEC:551534655$32\n");}, 700);
            setTimeout(() => {SerPort.write("NEC:551534655$32");}, 1500);
            
            break;

        case "volume up 5":
            SerPort.write("NEC:551502015$32\n");
            SerPort.write("NEC:551502015$32\n");
            SerPort.write("NEC:551502015$32\n");
            SerPort.write("NEC:551502015$32\n");
            SerPort.write("NEC:551502015$32\n");
            break;

        case "power on":
            SerPort.write("NEC:551489775$32");
            break;

        case "power off":
            SerPort.write("NEC:551489775$32");
            break;

        default:
            break;
    }
    if ((data + "").substring(0, (data + "").length - 1) == "TV")

        if ((data + "").substring(0, (data + "").length - 1) == "play")
            SerPort.write("NEC:551489775$32");



});

client.on('close', function () {
    console.log('Connection closed');
    setTimeout(() => {
        client.connect(1337, host, function () {
            console.log('Connected');
            //client.write('CONNECT');
        });
    }, 3000);
});

process.stdin.setEncoding('utf8');

process.stdin.on('readable', () => {
    let chunk;
    while ((chunk = process.stdin.read()) !== null) {
        if (chunk == '1\n') {
            console.log('Writing ' + 'SimulatorDeviceId')
            client.write(SimulatorDeviceId);
        } else {
            console.log('Writing ' + 'PhoneDeviceId')
            client.write(PhoneDeviceId)
        }
    }
});