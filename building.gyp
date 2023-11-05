{
  "targets": [
    {
      "target_name": "sonic-sensor",
      "sources": [ "src/sonic-sensor.c"],
      "include_dirs": ["<!@(node -p \"require('node-addon-api').include\")", "
    }
  ]
}