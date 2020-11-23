fn func(v: u32, c: u32) -> u32{
    return v*c
}

struct Exemplo<T> {
    a : T,
    b : T,
    c : T,
}

fn main (){
    let a: u32 = 10;
    let b: u32 = 30;
    let mut c = (a + b) / b;
    c = c / (a * b);
    if c > 0 { 
        while c <= 20 { 
            c += 1;
        }
    }
}