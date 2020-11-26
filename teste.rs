use std::io;

static ABC: u32  = 45;
fn func(v: u32 ,c: u32 ) -> u32 {
    return v*c
}
struct Exemplo {
bb: f32 ,
aa: u32 ,
cc: u32 ,
}
fn main() {
    let mut a: u32  = 10;
    let mut b: u32  = 30;
    let mut e: f32  = 39.000000;
    let mut c: u32  = (a+b)/b;
    c = c/(a*b);

    let d: u32 = func(a,b);
    if c > 1 && b < 10{
        while c <= 20{
            c = c+1;
        }

    }
    else {
        println!("{} ", d);

    }

}