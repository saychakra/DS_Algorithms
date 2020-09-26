import java.util.Random;

public class SegTrees {

	public static void main(String[] args) {
		// just creating an array of size 10 with random elements as of now
		Random random = new Random(5);
		int T=1000;
		for(int tt=0; tt < T; tt++) {
			//make a random array
			int n = 1 + random.nextInt(10);
			int[] a = new int[n];
			for(int i = 0; i < n; i++) a[i] = random.nextInt(10);
			
			// initiating segTree instance
			SegTree st=new SegTree(0, n-1, a);
			
			//answer a bunch of queries and updates to check if SegTree works
			int nQueries = 100;
			for(int qq=0; qq < nQueries; qq++) {
				if(random.nextBoolean()) {
					//range sum query
					int l = random.nextInt(n);
					int r = random.nextInt(n);
					int ans = 0;
					for(int i=l; i<=r; i++) ans+=a[i];
					
					//TODO: Query segTree
					int stSum = st.rangeSum(l, r);
					if(stSum != ans) {
						System.out.println("Tests not passed\n");
						throw null;
					}
					
				} else {
					//point update query
					int index = random.nextInt(n);
					int newVal = random.nextInt(10);
					a[index] = newVal;
					
					//TODO: update segTree
					st.pointUpdate(index, newVal);
				}
			}
			System.out.println("Test case : " + (tt+1) + " passed");
		}
		System.out.println("All tests passed!");
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