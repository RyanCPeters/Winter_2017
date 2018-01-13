### Background




Imagine you are writing a program that understands a limited subset of CSS, and you want to be able to parse color values in either of the following two formats:

`"#rgb"` or `"#rrggbb"`



where # is the '#' character and r,g, and b are hexadecimal digits (0-9, a-f, A-F) that represent the values of the red, green, and blue components of the color, respectively.



Doubling the hex digits of a value in the short format yields the same value in the long format, so for example,`"#fb0"` is the same color as `"#ffbb00"`.



### Your task



Write a function that accepts a string as input and returns the color that it represents, as a 32-bit integer where the red component is stored in the _lowest byte_, the green component is stored in the _second-lowest byte_, and the blue component is stored in the _third-lowest byte_. If the string does **not** match either the short or the long format, your function should throw an exception. If you are using a programming language that does not have exceptions, such as C, you should use a negative return value to indicate an error.



Assume that your function will be called very frequently, so try to avoid unnecessary inefficiencies in your code.



### Restrictions



<ul>
	<li>Your code cannot use library functions to convert the hex digits to numbers.</li>
	<li>Your code cannot use regular expressions.</li>
	<li>Your code must be 100% your own work, not be based on anyone else's code.</li>
</ul>



<h3>Examples</h3>



<span style="font-family:courier new,courier,monospace;">"#F00"    -&gt; 255 (red)

<span style="font-family:courier new,courier,monospace;">"#800080" -&gt; 8388736 (purple)

<span style="font-family:courier new,courier,monospace;">"#ffa500" -&gt; 42495  (orange)

<span style="font-family:courier new,courier,monospace;">"oops"    -&gt; error!




