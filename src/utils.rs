use std::collections::HashMap;

pub fn frequency(s: &str) -> HashMap<char, i32> {
    let mut h = HashMap::new();
    for ch in s.chars() {
        // insert 0 only if "ch" doesn't already exists
        let counter = h.entry(ch).or_insert(0);
        *counter += 1;
    }
    h
}

pub fn encode_string(s: &str, h: &HashMap<char, String>) -> String {
    let mut r = "".to_string();
    let mut t: Option<&String>;

    for ch in s.chars() {
        t = h.get(&ch);
        r.push_str(t.unwrap());
    }
    r
}

#[derive(Debug)]
pub struct Node {
    // The usage of Option is that this value might be None
    pub ch: Option<char>,
    pub freq: i32,
    // Box is simply a smart pointer to a heap allocated value,
    // basically this is how we work with pointers in the rusty way?
    pub left: Option<Box<Node>>,
    pub right: Option<Box<Node>>,
}

impl Node {
    pub fn new(freq: i32, ch: Option<char>) -> Node {
        Node {
            freq, ch,
            left: None, right: None,
        }
    }
}

pub fn assign_codes(p: &Box<Node>, h: &mut HashMap<char, String>, s: String) {
    // When the char field is not None, we add that char as key and s as its code
    if let Some(ch) = p.ch {
        h.insert(ch, s);
    } else {
        // Otherwise, recursively descend to the left and/or right
        if let Some(ref l) = p.left {
            assign_codes(l, h, s.clone() + "0");
        }
        if let Some(ref r) = p.right {
            assign_codes(r, h, s.clone() + "1");
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn first() {
        let expected: HashMap<char, i32> = [
            ('b', 2),
            ('a', 3),
            ('c', 1),
            ('d', 1)
        ].iter().cloned().collect();
        assert_eq!(frequency("abaabcd"), expected);
    }
}

