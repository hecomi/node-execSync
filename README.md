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
以下のコマンドを実行して下さい。

```
$ npm install node-execSync
```

使い方
--------------
次のように使います。

```javascript
var execSync = require('node-execSync');
console.log(exec('ls'));
```

詳細
--------------
その他詳細は Twitter:@hecomi へご質問いただくか、http://d.hatena.ne.jp/hecomi/ をご参照下さい。

