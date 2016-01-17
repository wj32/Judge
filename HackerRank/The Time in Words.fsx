let rec numberToHumString n =
  let teenOrTy = function
    | 3 -> "thir"
    | 5 -> "fif"
    | 6 -> "six"
    | 7 -> "seven"
    | 8 -> "eigh"
    | 9 -> "nine"
    | _ -> failwith "Invalid argument"
  match n with
  | 1 -> "one"
  | 2 -> "two"
  | 3 -> "three"
  | 4 -> "four"
  | 5 -> "five"
  | 6 -> "six"
  | 7 -> "seven"
  | 8 -> "eight"
  | 9 -> "nine"
  | 10 -> "ten"
  | 11 -> "eleven"
  | 12 -> "twelve"
  | 14 -> "fourteen"
  | 13 | 15 | 16 | 17 | 18 | 19 -> teenOrTy (n % 10) + "teen"
  | 20 -> "twenty"
  | 40 -> "forty"
  | 30 | 50 | 60 | 70 | 80 | 90 -> teenOrTy (n / 10) + "ty"
  | n when n <= 99 -> numberToHumString (n - n % 10) + " " + numberToHumString (n % 10)
  | _ -> failwith "Not implemented"

let timeToHumString = function
  | (h, 0) -> numberToHumString h + " o' clock"
  | (h, 1) -> "one minute past " + numberToHumString h
  | (h, 15) -> "quarter past " + numberToHumString h
  | (h, 30) -> "half past " + numberToHumString h
  | (h, 45) -> "quarter to " + numberToHumString (h + 1)
  | (h, 59) -> "one minute to " + numberToHumString (h + 1)
  | (h, m) when 1 < m && m < 30 -> numberToHumString m + " minutes past " + numberToHumString h
  | (h, m) when 30 < m && m < 59 -> numberToHumString (60 - m) + " minutes to " + numberToHumString (h + 1)
  | _ -> failwith "Invalid argument"

let h = stdin.ReadLine() |> int
let m = stdin.ReadLine() |> int
printfn "%s" (timeToHumString (h, m))
