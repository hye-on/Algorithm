function solution(code) {
    var answer = '';
    let mode =0;
    for(let i=0;i<code.length;i++){
       
        if(mode == 0){
            if(code[i]=='1'){
                mode =1;
            }else{
                if(i%2==0)
                    answer+=code[i];
            }
        }else{
            if(code[i]=='1'){
                mode =0;
            }else{
                if(i%2==1)
                    answer+=code[i];
            }
        }
    }
    
    if(answer=='')
        answer="EMPTY"
    
    return answer;
}