#include <node.h>

void RunMain(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();

  v8::Local<v8::Number> r = v8::Number::New(isolate, temperature);
  args.GetReturnValue().Set(temp);
}

void Init(v8::Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "main", RunMain);
}

NODE_MODULE(sonicsensor, Init)