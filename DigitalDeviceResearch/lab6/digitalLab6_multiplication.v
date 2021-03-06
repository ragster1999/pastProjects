// digitalLab6_multiplication.v
// march 12, 2020
// @author Alex Gonzalez and Kyle Wahlberg
// @version noneOfYourBidness
// #heckinYa

module digitalLab6_multiplication (m0, m1, m2, m3, m4, q0, q1, q2, q3, q4, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
	// Set inputs and outputs
	input m0, m1, m2, m3, m4, q0, q1, q2, q3, q4;
	output p0, p1, p2, p3, p4, p5, p6, p7, p8, p9;
	
	// Assign some jazz
	assign p0 = m0 & q0;
	and (maq1, q0, m1);
	and (maq2, q0, m2);
	and (maq3, q0, m3);
	and (maq4, q0, m4);
	and (maq5, maq4, 1);
	and (maq6, maq5, 1);
	and (mbq0, q1, m0);
	and (mbq1, q1, m1);
	and (mbq2, q1, m2);
	and (mbq3, q1, m3);
	and (mbq4, q1, m4);
	and (mbq5, mbq4, 1);
	
	// Call some adders
	fullAdder FA10(0, maq1, mbq0, p1, CFA10);
	fullAdder FA11(CFA10, maq2, mbq1, pp2, CFA11);
	fullAdder FA12(CFA11, maq3, mbq2, pp3, CFA12);
	fullAdder FA13(CFA12, maq4, mbq3, pp4, CFA13);
	fullAdder FA14(CFA13, maq5, mbq4, pp5, CFA14);
	fullAdder FA15(CFA14, maq6, mbq5, pp6, CFA15);
	
	// declare new round of mcq
	and (mcq0, q2, m0);
	and (mcq1, q2, m1);
	and (mcq2, q2, m2);
	and (mcq3, q2, m3);
	and (mcq4, q2, m4);
	and (mcq5, mcq4, 1);
	and (mcq6, mcq5, 1);
	
	// Sauce some more full addy bois
	fullAdder FB10(0, pp2, mcq0, p2, CFB10);
	fullAdder FB11(CFB10, pp3, mcq1, ppp3, CFB11);
	fullAdder FB12(CFB11, pp4, mcq2, ppp4, CFB12);
	fullAdder FB13(CFB12, pp5, mcq3, ppp5, CFB13);
	fullAdder FB14(CFB13, pp6, mcq4, ppp6, CFB14);
	fullAdder FB15(CFB14, CFA15, mcq5, ppp7, CFB15);
	
	// ay that's it fo B
	
	// My D Q !!
	and (mdq0, q3, m0);
	and (mdq1, q3, m1);
	and (mdq2, q3, m2);
	and (mdq3, q3, m3);
	
	// gimme a new round of fUlL adders
	fullAdder FC10(0, ppp3, mdq0, p3, CFC10);
	fullAdder FC11(CFC10, ppp4, mdq1, p4, CFC11);
	fullAdder FC12(CFC11, ppp5, mdq2, p5, CFC12);
	fullAdder FC13(CFC12, CFB13, mdq3, p6, p7); 
	
endmodule // multiplier


module fullAdder (Cin, x, y, s, Cout);
	input Cin, x, y;
	output s, Cout;
	assign s = x ^ y ^ Cin;
	assign Cout = (x & y) |  (x & Cin) | (y & Cin);
endmodule // fullAdder
