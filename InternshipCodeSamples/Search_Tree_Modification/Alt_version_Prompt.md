  <div aria-label="Question Content" class="challenge-text hrx-version ck_table-wrap fadeinContent" style="min-height:100px;"><h3>Background</h3>

<p>Imagine you are writing a program that understands a limited subset of CSS, and you want to be able to parse color values in either of the following two formats:</p>

<p><span style="font-family:courier new,courier,monospace;">"#rgb"</span> or <span style="font-family:courier new,courier,monospace;">"#rrggbb"</span></p>

<p>where <span style="font-family:courier new,courier,monospace;">#</span> is the '#' character and <span style="font-family:courier new,courier,monospace;">r</span>, <span style="font-family:courier new,courier,monospace;">g</span>, and <span style="font-family:courier new,courier,monospace;">b</span> are hexadecimal digits (0-9, a-f, A-F) that represent the values of the red, green, and blue components of the color, respectively.</p>


<p>Doubling the hex digits of a value in the short format yields the same value in the long format, so for example, <span style="font-family:courier new,courier,monospace;">"#fb0"</span> is the same color as <span style="font-family:courier new,courier,monospace;">"#ffbb00"</span>.</p>

<h3>Your task</h3>

<p>Write a function that accepts a string as input and returns the color that it represents, as a 32-bit integer where the red component is stored in the&nbsp;<em>lowest</em>&nbsp;byte, the green component is stored in the&nbsp;<em>second-lowest</em>&nbsp;byte, and the blue component is stored in the&nbsp;<em>third-lowest</em>&nbsp;byte. If the string does <strong>not</strong> match either the short or the long format, your function should throw an exception. If you are using a programming language that does not have exceptions, such as C, you should use a negative&nbsp;return value&nbsp;to indicate an error.</p>

<p>Assume that your function will be called very frequently, so try to avoid unnecessary inefficiencies in your code.</p>

<h3>Restrictions</h3>

<ul>
	<li>Your code cannot use library functions to convert the hex digits to numbers.</li>
	<li>Your code cannot use regular expressions.</li>
	<li>Your code must be 100% your own work, not be based on anyone else's code.</li>
</ul>

<h3>Examples</h3>

<p><span style="font-family:courier new,courier,monospace;">"#F00" &nbsp; &nbsp;-&gt; 255 &nbsp; &nbsp; &nbsp;</span>(red)</p>

<p><span style="font-family:courier new,courier,monospace;">"#800080" -&gt; 8388736 &nbsp;</span>(purple)</p>

<p><span style="font-family:courier new,courier,monospace;">"#ffa500" -&gt; 42495 &nbsp; &nbsp;</span>(orange)</p>

<p><span style="font-family:courier new,courier,monospace;">"oops"</span>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; -&gt; &nbsp;error!</p>
