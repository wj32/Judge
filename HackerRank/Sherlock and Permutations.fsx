let P = 1000000007I
let fallingFactorial = let rec loop acc x = function 0 -> acc | n -> loop ((acc * x) % P) (x - 1I) (n - 1) in loop 1I
let binomial x n = ((fallingFactorial x n) * bigint.ModPow(fallingFactorial (bigint n) n, P - 2I, P)) % P
for _ in {1 .. stdin.ReadLine() |> int} do
  match stdin.ReadLine().Split(' ') |> Array.map int with
  | [|n; m|] ->
    printfn "%A" (binomial (bigint m + bigint n - 1I) n)
  | _ ->
    failwith "Invalid input"
