

const operations = {
    w: (n) => n+1,
    s: (n) => n-1,
    d: (n) => n+10,
    a: (n) =>n-10,
};

function solution(n, control) {

    //콜백, 초기값
    // 콜백 : 누적값(이전값), 현재 값, 인덱스, 전체 배열
    return [...control].reduce((prev,op) => operations[op](prev),n);
}
