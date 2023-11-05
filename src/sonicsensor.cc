#include <node.h>

void GetTemperature(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();
  double temperature = 25.5; // Assuming the temperature sensor returns 25.5°C

  v8::Local<v8::Number> temp = v8::Number::New(isolate, temperature);
  args.GetReturnValue().Set(temp);
}

void Init(v8::Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "main", GetTemperature);
}

NODE_MODULE(sonicsensor, Init)