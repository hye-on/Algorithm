function solution(num_list) {
    var answer = 0;
    const multi = num_list.reduce((acc,cur) =>{
        return acc*cur;
    },1);
    
    const sum = num_list.reduce((acc,cur)=>{
       return acc+cur; 
    },0);
    answer = multi < Math.pow(sum,2) ? 1 : 0;
    return answer;
}