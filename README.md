node-execSync
==============

はじめに
--------------
node.js の child_process 下の exec 関数の同期版です。
shell のコマンドを引数で指定して実行して、その実行結果を戻り値で返してくれます。

ライセンス
--------------
NYSL ライセンスです。

インストール
--------------
git clone して次のコマンドを実行して下さい。

	$ node-waf configure build

wscript ファイル内の gcc のバージョンは適宜変更して下さい。デフォルトでは、g++-4.8 でコンパイルしています。

使い方
--------------
次のように使います。

	var exec = require('./build/Release/shell').execSync;
	console.log(exec('ls -all'));

詳細
--------------
その他詳細は http://d.hatena.ne.jp/hecomi/ をご参照下さい。

