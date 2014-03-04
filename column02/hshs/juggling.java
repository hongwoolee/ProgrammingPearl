public class Juggling {
	
	/**
	 * input 전체길이, 바꿀길이
	 * output 로테이트된 백터
	 * @param args
	 */
	private void juggling(int a, int b){
		String str = makeString(a);
		System.out.println(str);
		
	}
	
	private int gcb(int a, int b){
		int mok = b;
		
		for(int i = 0; mok > 0; mok--){
			if(a%mok == 0 && b%mok == 0){
				return mok;
			}
		}
		return -1;
	}
	
	private String makeString(int length){
		String str = "";
		for(int i=97; i<length+97; i++){
			char chr = (char) i;
			str += chr;
		}
		return str;
	}
	
	public static void main(String[] args) {
		System.out.println("hi");
		int total =15;
		int change = 2;
		System.out.println(new Juggling().gcb(total, change));
		
		new Juggling().juggling(total, change);
	}
}
