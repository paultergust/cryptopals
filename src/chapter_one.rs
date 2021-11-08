use hex;
use base64;

pub fn hex_to_base64(hex: &str) -> String {
    let decoded = hex_to_bytes(hex);
    let encoded = base64::encode(&decoded);
    encoded
}

pub fn fixed_xor(input_one: &str, input_two: &str) -> String {
    let input_one = hex_to_bytes(input_one);
    let input_two = hex_to_bytes(input_two);
    let xored_vector:Vec<u8> = input_one
            .iter()
            .zip(input_two)
            .map(|(x1, x2)| x1 ^ x2)
            .collect();
    hex::encode(xored_vector)
}

fn hex_to_bytes(hex: &str) -> Vec<u8> {
    hex::decode(hex).expect("Decoding failed")
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    pub fn test_hex_to_base64() {
        let input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
        let encoded = hex_to_base64(input);

        let expected = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

        assert_eq!(expected, encoded);
    }

    #[test]
    pub fn test_fixed_xor() {
        let input_one = "1c0111001f010100061a024b53535009181c";
        let input_two = "686974207468652062756c6c277320657965";
        let encoded = fixed_xor(input_two, input_one);

        let expected = "746865206b696420646f6e277420706c6179";

        assert_eq!(expected, encoded);
    }
}
