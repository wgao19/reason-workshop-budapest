let v1 = 43242;
let v2 = 234;
let v3 = 4534;

let average = (v1 + v2 + v3) / 3;
//////////////////////////////////////////////////////////////////////////////////////////
let average_in_float =
  (float_of_int(v1) +. float_of_int(v2) +. float_of_int(v3)) /. 3.;

//////////////////////////////////////////////////////////////////////////////////////////
let average_3 = (a1, a2, a3) => (a1 +. a2 +. a3) /. 3.;

//////////////////////////////////////////////////////////////////////////////////////////

print_endline(
  "====
print some list, does it look different than you expected? Is is different than array? Can you convert list to array?
====",
);
let print_some_list = a_list => List.map(el => print_endline(el), a_list);
print_some_list([string_of_int(1), string_of_int(2), string_of_int(3)]);

print_endline("end of exercise 3");

//////////////////////////////////////////////////////////////////////////////////////////

print_endline("====================== JS.log =======================");
Js.log("js log");

//////////////////////////////////////////////////////////////////////////////////////////

print_endline("====================== JS.log2 ======================");
Js.log2(v1, "js log2");
Js.log2(3.0, 3);
print_endline("JS.log2 takes 2 argument and prints them side-by-side");

//////////////////////////////////////////////////////////////////////////////////////////

print_endline("====================== JS.log3 ======================");
Js.log3(1, 2, 3);
let three = 3.0;
Js.log3("first thing", 2, three);

/////////////////////////////////////////////////////////////////////////////////////////

print_endline("=== make some arguments of average function named ===");

let average_named = (~a1, ~a2, ~a3) => (a1 +. a2 +. a3) /. 3.0;

print_string(Js.Float.toString(average_named(~a1=3.0, ~a2=4.0, ~a3=1.0)));

Js.Array.map(x => x +. 1.0, [|1.0, 2.0, 3.0|]);

let increment = x => x + 1;

let average_named_optional = (~a1, ~a2=0, ~a3=0, ()) =>
  (float_of_int(a1) +. float_of_int(a2) +. float_of_int(a3)) /. 3.0;

print_newline();

////////////// generalize average fn to take list //////////////////

print_endline("====================== sum list =====================");

let sum_list = li => List.fold_left((a, b) => a + b, 0, li);
print_endline(Js.Int.toString(sum_list([1, 2, 3, 4])));

let average_list = li =>
  float_of_int(sum_list(li)) /. float_of_int(List.length(li));

print_endline(Js.Float.toString(average_list([1, 2, 3, 4])));

///////////////// change average fn to take array /////////////////////

print_endline("====================== sum array ====================");

let sum_array = arr => Array.fold_left((a, b) => a + b, 0, arr);
print_endline(Js.Int.toString(sum_array([|1, 2, 3, 4|])));

let average_array = arr => (
  float_of_int(sum_array(arr)) /. float_of_int(Array.length(arr)),
  Array.length(arr),
);
let (avg, _) = average_array([|1, 2, 3, 4|]);
print_endline(Js.Float.toString(avg));