class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def solve(ind,ans,temp):
            if ind==len(nums):
                ans.append(temp.copy())
                return 
            temp.append(nums[ind])
            solve(ind+1,ans,temp)
            temp.pop()
            solve(ind+1,ans,temp)
            
        ans = []
        solve(0,ans,[])
        return ans

# solve(0, ans, [])

# |

# +-- Include 1: solve(1, ans, [1])

# |   |

# |   +-- Include 2: solve(2, ans, [1, 2])

# |   |   |

# |   |   +-- Include 3: solve(3, ans, [1, 2, 3])

# |   |   |   |

# |   |   |   +-- ans.append([1, 2, 3]) (base case reached, add to ans)

# |   |   |

# |   |   +-- Exclude 3: solve(3, ans, [1, 2])

# |   |       |

# |   |       +-- ans.append([1, 2]) (base case reached, add to ans)

# |   |

# |   +-- Exclude 2: solve(2, ans, [1])

# |       |

# |       +-- Include 3: solve(3, ans, [1, 3])

# |       |   |

# |       |   +-- ans.append([1, 3]) (base case reached, add to ans)

# |       |

# |       +-- Exclude 3: solve(3, ans, [1])

# |           |

# |           +-- ans.append([1]) (base case reached, add to ans)

# |

# +-- Exclude 1: solve(1, ans, [])

#     |

#     +-- Include 2: solve(2, ans, [2])

#     |   |

#     |   +-- Include 3: solve(3, ans, [2, 3])

#     |   |   |

#     |   |   +-- ans.append([2, 3]) (base case reached, add to ans)

#     |   |

#     |   +-- Exclude 3: solve(3, ans, [2])

#     |       |

#     |       +-- ans.append([2]) (base case reached, add to ans)

#     |

#     +-- Exclude 2: solve(2, ans, [])

#         |

#         +-- Include 3: solve(3, ans, [3])

#         |   |

#         |   +-- ans.append([3]) (base case reached, add to ans)

#         |

#         +-- Exclude 3: solve(3, ans, [])

#             |

#             +-- ans.append([]) (base case reached, add to ans)