const tempsensor = require('./build/Release/tempsensor.node');

module.exports = function(RED) {
    function TempSensorNode(config) {
        RED.nodes.createNode(this, config);
        const node = this;

        node.on('input', function(msg) {
            // Call the native addon to get the temperature
            const temperature = tempsensor.getTemperature();

            msg.payload = temperature;
            node.send(msg);
        });
    }

    RED.nodes.registerType("temp-sensor", TempSensorNode);
}