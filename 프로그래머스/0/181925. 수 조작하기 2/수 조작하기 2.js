function solution(numLog) {
    var answer = '';
    
//     for(let i=0;i<numLog.length-1;i++){
//         let pre = numLog[i];
//         let nxt = numLog[i+1];
        
//         if(pre+1===nxt)
//             answer+='w';
//         else if(pre-1===nxt)
//             answer+='s';
//         else if(pre+10===nxt)
//             answer+='d';
//         else
//             answer+='a';
        
//     }
    
    numLog.forEach((pre, i) => {
        if (i === numLog.length - 1) return; 
        const nxt = numLog[i + 1];
        const diff = nxt - pre;

        const directions = {
            '1': 'w',
            '-1': 's',
            '10': 'd',
            '-10': 'a',
        };

        answer += directions[diff] ; 
    });

 
    return answer;
}