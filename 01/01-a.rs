use std::env;
use std::fs;

struct Position {
    depth: u64,
    distance: u64
}

impl Position {
    fn move_submarine(&mut self, operation: &String, amount: u64) {
        if operation == "forward" {
            self.distance += amount;
        } else if operation == "down" {
            self.depth += amount;
        } else if operation == "up" {
            if amount > self.depth {
                self.depth = 0;
            } else {
                self.depth -= amount;
            }
        }
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let filename: String = String::from(args.get(1).unwrap());

    let mut position = Position { depth: 0, distance: 0};

    let contents: String = fs::read_to_string(filename)
        .expect("noup");
    for line in contents.lines() {
        let mut iter = line.split_whitespace();
        let operation: String = String::from(iter.next().unwrap());
        let amount: u64 = iter.next().unwrap().parse::<u64>().unwrap();
        position.move_submarine(&operation, amount);
    }
    println!("{:?}", position. depth * position.distance);
}
