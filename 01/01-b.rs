use std::env;
use std::fs;

struct Position {
    depth: i64,
    distance: i64,
    aim: i64
}

impl Position {
    fn move_submarine(&mut self, operation: &String, amount: i64) {
        if operation == "forward" {
            self.distance += amount;
            self.depth += self.aim * amount;

            if self.depth < 0 {
                self.depth = 0;
            }
        } else if operation == "down" {
            self.aim += amount;
        } else if operation == "up" {
            self.aim -= amount;
        }
    }

    fn print_result(&self) {
        println!("depth {}", self.depth);
        println!("distance {}", self.distance);
        println!("result: {}", self.distance * self.depth);
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let filename: String = String::from(args.get(1).unwrap());

    let mut position = Position { depth: 0, distance: 0, aim: 0};

    let contents: String = fs::read_to_string(filename)
        .expect("noup");
    for line in contents.lines() {
        let mut iter = line.split_whitespace();
        let operation: String = String::from(iter.next().unwrap());
        let amount: i64 = iter.next().unwrap().parse::<i64>().unwrap();
        position.move_submarine(&operation, amount);
    }
    position.print_result();
}
