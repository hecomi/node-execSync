#include <iostream>
#include <string>
#include <cstdlib>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <node.h>

using namespace v8;
namespace io = boost::iostreams;
typedef io::stream<io::file_descriptor_source> boost_stream;

Handle<Value> execSync(const Arguments& args)
{
	HandleScope scope;

	// 引数が文字列かどうかチェック
	if (!args[0]->IsString()) {
		Local<String> msg = String::New("[execSync] Error! Argument of 'execSync' must be String.");
		ThrowException(Exception::TypeError(msg));
		return scope.Close(Undefined());
	}
	String::Utf8Value command(args[0]);

	FILE *fp = popen(*command, "r");
	if (fp == nullptr) {
		Local<String> msg = String::New("[execSync] Error! 'popen' failed.");
		ThrowException(Exception::TypeError(msg));
		return scope.Close(Undefined());
	}

	boost_stream bs(fileno(fp), io::close_handle);
	std::string line, result;
	while (std::getline(bs, line)) {
		result += line + "\n";
	}

	return scope.Close(String::New(result.c_str()));
}

void init(Handle<Object> target) {
	target->Set(
		String::NewSymbol("execSync"),
		FunctionTemplate::New(execSync)->GetFunction()
	);
}

NODE_MODULE(shell, init)

