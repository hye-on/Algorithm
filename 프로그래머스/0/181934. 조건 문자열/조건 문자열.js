function solution(ineq, eq, n, m) {
    const operator = ineq + (eq === "=" ? "=" : ""); 
    return eval(`${n} ${operator} ${m}`) ? 1 : 0;
    
    
}