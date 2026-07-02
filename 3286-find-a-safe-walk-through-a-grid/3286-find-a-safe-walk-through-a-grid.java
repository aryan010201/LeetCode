class Solution {

    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        int m=grid.size();
        int n=grid.get(0).size();

        int[][] vis = new int[m][n];
        

        PriorityQueue<int[]> pq=new PriorityQueue<>((a, b) -> b[0] - a[0]);
        if(grid.get(0).get(0)==1){
            health--;
        }

        if(health<=0){
            return false;
        }

        int[] x={0,1,0,-1};
        int[] y={1,0,-1,0};
        pq.add(new int[]{health,0,0});
        vis[0][0]=1;

        while(!pq.isEmpty()){
            int[] top=pq.poll();
            int currHealth=top[0];
            int row=top[1];
            int col=top[2];
            if(row==m-1 && col==n-1){
                return true;
            }
            for(int i=0;i<4;i++){
                int newRow=row+x[i];
                int newCol=col+y[i];
                if(newRow<m && newRow>=0 && newCol<n && newCol>=0 && vis[newRow][newCol]==0){
                    if(grid.get(newRow).get(newCol)==0){
                        pq.add(new int[]{currHealth,newRow,newCol});
                        vis[newRow][newCol]=1;
                    }
                    else if(grid.get(newRow).get(newCol)==1 && currHealth>1 &&vis[newRow][newCol]==0 ){
                        pq.add(new int[]{currHealth-1,newRow,newCol});
                        vis[newRow][newCol]=1;
                    }
                }
            }


        }
        return false;  
    }
}