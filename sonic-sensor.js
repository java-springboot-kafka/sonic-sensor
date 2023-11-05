const sonicSensor = require('./build/Release/sonic-sensor.node');

module.exports = function(RED) {
    function SonicSensorNode(config) {
        RED.nodes.createNode(this, config);
        const node = this;

        node.on('input', function(msg) {
            // Call the native addon to get the temperature
            const distance = sonicSensor.main();

            msg.payload = distance;
            node.send(msg);
        });
    }

    RED.nodes.registerType("sonic-sensor", SonicSensorNode);
}