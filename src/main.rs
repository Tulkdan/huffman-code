use std::collections::HashMap;
use utils::{assign_codes, frequency, Node};

mod utils;

fn new_box(n: Node) -> Box<Node> {
    Box::new(n)
}

fn main() {
    let h = frequency("abaabcd");

    let mut p: Vec<Box<Node>> =
        h.iter()
        .map(|x| new_box(Node::new(*(x.1), Some(*(x.0)))))
        .collect();

    // function to create the huffman tree
    while p.len() > 1 {
        // sorting the array by freq
        p.sort_by(|a, b| (&(b.freq)).cmp(&(a.freq)));
        let a = p.pop().unwrap();
        let b = p.pop().unwrap();

        let mut c = new_box(Node::new(a.freq + b.freq, None));
        c.left = Some(a);
        c.right = Some(b);
        p.push(c);
    }

    let root = p.pop().unwrap();

    let mut h: HashMap<char, String> = HashMap::new();
    assign_codes(&root, &mut h, "".to_string());

    println!("{:?}", h);
}
