function solution(my_string, k) {
    var answer = '';
    // while(k--){
    //     answer+=my_string;
    // }
    
    answer= my_string.repeat(k);
    return answer;
}