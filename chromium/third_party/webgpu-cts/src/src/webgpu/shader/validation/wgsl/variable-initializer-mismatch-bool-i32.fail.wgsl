// v-0033: variable 'flag' store type is 'bool' however the initializer type is 'i32'.

var<private> flag : bool  = 0;

@stage(compute) @workgroup_size(1)
fn main() {
}
