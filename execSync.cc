#include <string>
#include <cstdlib>
#include <node.h>

using namespace v8;

Handle<Value> execSync(const Arguments& args)
{
	HandleScope scope;

	if (!args[0]->IsString()) {
		Local<String> msg = String::New("Argument of 'execsync' must be String.");
		ThrowException(Exception::TypeError(msg));
		return scope.Close(Undefined());
	}
	String::Utf8Value command(args[0]);

	FILE *fp = popen(*command, "r");
	if (fp == NULL) {
		Local<String> msg = String::New("'popen' in 'execSync' failed.");
		ThrowException(Exception::TypeError(msg));
		return scope.Close(Undefined());
	}

	const int BUF_SIZE = 1024;
	char buf[BUF_SIZE];
	std::string result;
	while ( fgets(buf, BUF_SIZE, fp) != NULL ) {
		result += buf;
	}

	pclose(fp);

	return scope.Close(String::New(result.c_str()));
}

void init(Handle<Object> target) {
	target->Set(
		String::NewSymbol("execSync"),
		FunctionTemplate::New(execSync)->GetFunction()
	);
}

NODE_MODULE(shell, init)

