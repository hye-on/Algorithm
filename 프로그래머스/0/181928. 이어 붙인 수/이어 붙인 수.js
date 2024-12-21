function solution(num_list) {
    var answer = 0;
    let a="",b="";
    for(const num of num_list){
        if(num%2===0)
            a+=num;
        else
            b+=num;
            
    }
    return answer = Number(a)+Number(b);
}