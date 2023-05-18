public class ComplexNumber {
	private double realPart;
	private double imaginaryPart;
	public static final double EPSILON = 0.001;
	
	public ComplexNumber(double realPart, double imaginaryPart){
		this.realPart = realPart;
		this.imaginaryPart = imaginaryPart;
	}
	
	public double getRealPart() {
		return	this.realPart;
	}
	
	public double getImaginaryPart() {
		return	this.imaginaryPart;
	}
	
	public double getRadius() {
		return Math.sqrt(this.realPart*this.realPart + this.imaginaryPart*this.imaginaryPart);
	}

	public double getArgument() {
		return Math.atan2(imaginaryPart, realPart);
	}
	
	public boolean almostEquals(ComplexNumber other) {
		return Math.abs(this.getRadius() - other.getRadius()) < ComplexNumber.EPSILON;
	}
	
	public static ComplexNumber fromPolarCoordinates(double radius, double argument) {
		return new ComplexNumber(radius*Math.cos(argument), radius*Math.sin(argument));
	}
	
	public ComplexNumber plus(ComplexNumber other) {
		return new ComplexNumber(this.realPart+other.realPart, this.imaginaryPart+other.imaginaryPart);
	}
	
	public ComplexNumber minus(ComplexNumber other) {
		return new ComplexNumber(this.realPart-other.realPart, this.imaginaryPart-other.imaginaryPart);
	}
	
	ComplexNumber times(ComplexNumber other) {
		double r1 = this.getRadius(), r2 = other.getRadius();
		double theta1 = this.getArgument(), theta2 = other.getArgument();
		return ComplexNumber.fromPolarCoordinates(r1*r2, theta1+theta2);
	}

	ComplexNumber divide(ComplexNumber other) {
		double r1 = this.getRadius(), r2 = other.getRadius();
		double theta1 = this.getArgument(), theta2 = other.getArgument();
		return ComplexNumber.fromPolarCoordinates(r1/r2, theta1-theta2);
	}

}
