let P = 1000000007I
let fallingFactorial = let rec loop acc x = function 0 -> acc | n -> loop ((acc * x) % P) (x - 1I) (n - 1) in loop 1I
let binomial x n = ((fallingFactorial x n) * bigint.ModPow(fallingFactorial (bigint n) n, P - 2I, P)) % P
{1 .. stdin.ReadLine() |> int} |> Seq.iter (fun _ -> stdin.ReadLine().Split(' ') |> Array.map int |> function [|m; n|] -> printfn "%A" (binomial (bigint (m + n - 2)) (m - 1)) | _ -> failwith "Invalid input")