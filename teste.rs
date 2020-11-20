static A: i64 = 10;
static mut B: i64 = 0;

fn func(v: i64) -> i64{
    v*2
}

struct exemplo<T> {
    i64 a : T;
    f64 b : T;
    i64 c : T;
}

fn main() {
    unsafe{
        B = 30;
        let mut c = (A + B) / B;
        c = c / (A * B);
        println!("{}", c);
    }
}