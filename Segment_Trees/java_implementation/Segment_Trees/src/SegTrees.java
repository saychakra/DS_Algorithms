import java.util.Random;

public class SegTrees {

	public static void main(String[] args) {
		// just creating an array of size 10 with random elements as of now
		Random random = new Random(5);
		int n = 10;
		int[] arr = new int[n];
		for (int i=0; i<n; ++i) {
			arr[i] = 1+random.nextInt(10);
		}
		//printing the array for reference:
		System.out.println("Array Elements:");
		for(int val : arr) System.out.print(val + " ");
		System.out.println();
		
		// range sum query
		int l = 2, r = 4;
		int slowSum = 0;
		System.out.println("Querying sum between " + l + " " + r);
		for (int i=l; i<=r; ++i) {
			slowSum += arr[i];
		}
		System.out.println("Actual sum in slow way: " + slowSum);
		
		SegTree st = new SegTree(0, n-1, arr);
		int stRangeSum = st.rangeSum(l, r);
		System.out.println("Segment Tree range sum: " + stRangeSum);
		if(stRangeSum == slowSum) {
			System.out.println("Segment tree worked :)");
		} else {
			System.out.println("No Match :(");
		}
	}
	
	static class SegTree {
		int leftmost, rightmost;
		SegTree lChild, rChild;
		int sum;
		
		public SegTree(int leftmost, int rightmost, int arr[]) {
			this.leftmost = leftmost;
			this.rightmost = rightmost;
			
			//for leaf nodes
			if (leftmost == rightmost) {
				sum = arr[leftmost];
			} else {
				// otherwise there are two children
				int mid = (leftmost+rightmost) / 2;
				//[l, mid] and [mid+1, r]
				lChild = new SegTree(leftmost, mid, arr);
				rChild = new SegTree(mid+1, rightmost, arr);
				
				recalc();
			}
		}
		
		// this needs to be called when we know one of our two children changes
		public void recalc() {
			if(leftmost == rightmost) return; // this is the leaf and considering sum is stored correctly
			
			// otherwise sum is based on the sum of the two child segments
			sum = lChild.sum + rChild.sum;
		}
		
		public void pointUpdate(int index, int newVal) {
			//if this is the leaf
			if (rightmost == leftmost) {sum = newVal; return;}
			else {
				// update the two kids
				
				// in the range of the left child
				if(index <= lChild.rightmost)	lChild.pointUpdate(index, newVal);
				//otherwise the right child needs to be updated
				else							rChild.pointUpdate(index, newVal);
				recalc();
			}
		}
		
		public int rangeSum(int l, int r) {
			// entirely disjoint
			if (l > rightmost || r < leftmost) return 0;
			
			// if entirely covers us
			if (l <= leftmost && r >= rightmost) return sum;
			
			// case where we don't know, the locations and hence need to ask the left and right children
			return lChild.rangeSum(l, r) + rChild.rangeSum(l, r);
		}
	}
}