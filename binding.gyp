{
  "targets": [
      {
        "target_name": "sonic-sensor",
        "sources": [
          "src/sonic-sensor.cc"
        ],
        "include_dirs": [
          "<!@(node -p \"require('nan')\")",
          "<!@(node -p \"require('node-addon-api').include\")"
        ],
        "cflags": [
          "-std=c++11",
          "-Wall"
        ],
        "xcode_settings": {
          "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
          "GCC_ENABLE_CPP_RTTI": "YES"
        },
        "msvs_settings": {
          "VCCLCompilerTool": {
            "ExceptionHandling": 1,
            "RuntimeLibrary": 3
          }
        }
      }
    ]
}