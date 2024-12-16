function solution(n) {
    var answer = 0;
    if(n%2==1){
        answer = ((n+1)/2/2)*(1+n);
    }else{
        let m = n/2;
          answer = n*(n+1)*(n+2)/6;
    }
    return answer;
}