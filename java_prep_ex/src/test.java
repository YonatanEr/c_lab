
public class test {

	public static void main(String[] args) {
		double a, b, c, d;
		a=0;b=0;c=0;d=0;
		ComplexNumber x = new ComplexNumber(a, b);
		ComplexNumber y = new ComplexNumber(c, d);
		print_complex_number(x.plus(y));
		print_complex_number(x.minus(y));
		print_complex_number(x.times(y));
		print_complex_number(x.divide(y));
	}
	
	public static void print_complex_number(ComplexNumber num){
		System.out.println(String.valueOf(num.getRealPart()) + " + " + String.valueOf(num.getImaginaryPart()) + "j\n");
	}
}
