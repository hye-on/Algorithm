const fs = require('fs');


const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');


const n = parseInt(input[0], 10);


const grid = [];
for (let i = 1; i <= n; i++) {
  grid.push(...input[i].split(''));
}

const cal = (a, b) => {
  const ay = Math.floor(a / n);
  const ax = a % n;

  const by = Math.floor(b / n);
  const bx = b % n;

  const dy = ay - by;
  const dx = ax - bx;

  return dx !== 0 ? dy / dx : 1; // dx가 0일 때 기울기 1로 처리
};

let answer = 0;

for (let i = 0; i < n * n; i++) {
  if (grid[i] === '.') continue; 
  for (let j = i + 1; j < n * n; j++) {
    if (grid[j] === '.') continue; 

    const g = cal(i, j); 

    for (let k = j + 1; k < n * n; k++) {
      if (grid[k] === '.') continue; 

      // 점 i, j, k가 같은 직선 상에 있는지 확인
      if (g === cal(i, k) && g === cal(j, k)) {
        answer++;
      }
    }
  }
}

console.log(answer);
