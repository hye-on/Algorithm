function solution(num_list) {
    var answer = [];
    const last_el = num_list.at(-1);
    const second_last_el = num_list.at(-2);
    
    const new_num = last_el>second_last_el ? last_el - second_last_el : last_el*2;
    answer = num_list;
    answer.push(new_num);
    return answer;
}