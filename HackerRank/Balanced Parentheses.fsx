open System

let balanced (s : string) =
  let rec loop i opened =
    if i = s.Length then
      List.isEmpty opened
    else
      match s.[i], opened with
      | '{', opened | '(', opened | '[', opened -> loop (i + 1) (s.[i] :: opened)
      | '}', '{' :: opened | ')', '(' :: opened | ']', '[' :: opened -> loop (i + 1) opened
      | _ -> false
  loop 0 []

let t = Console.ReadLine() |> int

for _ in 1 .. t do
  let s = Console.ReadLine()
  printfn "%s" (if balanced s then "YES" else "NO")
