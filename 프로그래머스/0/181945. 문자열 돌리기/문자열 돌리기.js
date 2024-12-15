const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = [line];
}).on('close',function(){
    str = input[0];
    //map은 함수를 반환한 함수가 필요할 때 더 적절
    // str.split('').map(
    // ch => console.log(ch);
    // );
    // for(let i=0;i<str.length;i++){
    //     console.log(str.charAt(i));
    // }
    

    
     [...str].forEach(ch => console.log(ch));
  
//     for(const ch of str){
//         console.log(ch);
//     }

});