let P = 1000000007L

let indexOfLetter (letter : char) = int letter - int 'a'

module Trie =
  type T = {children : T option array; mutable stop : bool}
  
  let create () = {children = Array.init 10 (fun _ -> None); stop = false}
  
  let containsConcat (s : string) root =
    let rec loop i t =
      if i = s.Length then
        t.stop
      else
        let index = indexOfLetter s.[i]
        (
          match t.children.[index] with
          | Some child -> loop (i + 1) child
          | None -> false
        ) || (if t.stop then loop i root else false)
    loop 0 root
  
  let add (s : string) t =
    let rec loop i t =
      if i = s.Length then
        t.stop <- true
      else
        let index = indexOfLetter s.[i]
        let child =
          match t.children.[index] with
          | Some child -> child
          | None ->
            let child = create ()
            t.children.[index] <- Some child
            child
        loop (i + 1) child
    loop 0 t

let memoize1D ni invalid (f : (int -> 'a) -> int -> 'a) =
  let mem = Array.create ni invalid
  let rec g i =
    h g i
  and h r i =
    if 0 <= i && i < ni then
      match mem.[i] with
      | value when value <> invalid -> value
      | value ->
        let value = f g i
        mem.[i] <- value
        value
    else
      f g i
  g

let limit = 100

let case s m =
  let s =
    s
    |> Seq.fold
      (fun (list, trie) s ->
        if not (Trie.containsConcat s trie) then
          Trie.add s trie
          (s :: list, trie)
        else
          (list, trie))
      ([], Trie.create ())
    |> fst
    |> List.toArray
    |> Array.rev
  let solution = memoize1D (limit + 1) -1L (fun r m ->
    match m with
    | m when m < 0 -> 0L
    | 0 -> 1L
    | m ->
      let mutable sum = 0L
      for i = 0 to s.Length - 1 do
        sum <- (sum + r (m - s.[i].Length)) % P
      sum)
  {0 .. m} |> Seq.fold (fun acc i -> (acc + solution i) % P) 0L

match stdin.ReadLine().Split(' ') |> Array.map int with
| [|n; m|] ->
  let s =
    {1 .. n}
    |> Seq.map (fun _ -> stdin.ReadLine())
    |> Seq.toArray
    |> Array.sortBy String.length
  printfn "%d" (case s m)
| _ ->
  failwith "Invalid input"
