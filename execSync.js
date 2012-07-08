var exec = require('./build/Release/shell').execSync;

console.log(exec('ls -all'));

