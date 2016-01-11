open System

let rec gcd x y =
  if x = 0 then
    y
  else
    gcd (y % x) x

let reduceFrac (top, bottom) =
  let d = gcd top bottom
  (top / d, bottom / d)

let rec sumUniformProbability a b c =
  if a > b then
    sumUniformProbability b a c
  else
    if c < 0 then
      (0, 1)
    else if c < a then
      (c * c, 2 * a * b)
    else if c < b then
      (2 * c - a, 2 * b)
    else if c < a + b then
      (a * (2 * b - a) - (c - b - 2 * a) * (c - b), 2 * a * b)
    else
      (1, 1)

let n = Console.ReadLine() |> int

for i in 1 .. n do
  match Console.ReadLine().Split(' ') |> Array.map int with
  | [| a; b; c |] ->
    let (top, bottom) = sumUniformProbability a b c |> reduceFrac
    printfn "%d/%d" top bottom
  | _ ->
    failwith "Unexpected input"
