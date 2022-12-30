if(operator){
    if(precedence(i) >= stack(top)){
        stack.push(i)
    }
    else{
        while(stack is not empty){
            str += stack.pop();
        }
        stack.push(i);
    }
}

x+y*z-k
xyz*+k-

xyz*+k- 