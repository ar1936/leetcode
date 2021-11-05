class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        boolean ans=false;
        for(int i=0;i<matrix.length;i++){
            if(matrix[i][0]<=target&&matrix[i][matrix[i].length-1]>=target){
                for(int j=0;j<matrix[i].length;j++){
                    if(matrix[i][j]==target)
                        return true;
                }
            }
        }
        return false;
    }
}