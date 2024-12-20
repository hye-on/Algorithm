const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cube = new Array(25).fill(0); // 1-indexed

const rotations = [
    [1,3,5,7,9,11,24,22],
    [2,4,6,8,10,12,23,21],
    [13,14,5,6,17,18,21,22],
    [15,16,7,8,19,20,23,24],
    [1,2,18,20,12,11,15,13],
    [3,4,17,19,10,9,16,14]
];

function check_cube() {
    for (let i = 1; i <= 24; i += 4) {
        if (cube[i] !== cube[i+1] || cube[i] !== cube[i+2] || cube[i] !== cube[i+3]) {
            return false;
        }
    }
    return true;
}

function rotate(face, clockwise) {
    let temp = new Array(8);
    for (let i = 0; i < 8; i++) {
        temp[i] = cube[rotations[face][i]];
    }
    
    if (clockwise) {
        for (let i = 0; i < 8; i++) {
            cube[rotations[face][(i+2)%8]] = temp[i];
        }
    } else {
        for (let i = 0; i < 8; i++) {
            cube[rotations[face][i]] = temp[(i+2)%8];
        }
    }
}

function solve() {
    for (let face = 0; face < 6; face++) {
        let original = [...cube];
        
        // 시계 방향 회전
        rotate(face, true);
        if (check_cube()) return true;
        
        // 원상태로 복구 후 반시계 방향 회전
        cube = [...original];
        rotate(face, false);
        if (check_cube()) return true;
        
        // 원상태로 복구
        cube = [...original];
    }
    return false;
}

let inputCount = 0;
rl.on('line', (line) => {
    let inputs = line.split(' ').map(Number);
    for(let i = 0; i < inputs.length; i++) {
        cube[++inputCount] = inputs[i];
    }
    
    if(inputCount === 24) {
        console.log(solve() ? 1 : 0);
        rl.close();
    }
});
