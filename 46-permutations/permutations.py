class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def solve(ind,ans):
            if len(nums)==ind:
                ans.append(nums.copy())
                return 
            for i in range(ind,len(nums)):
                nums[i],nums[ind] = nums[ind], nums[i]
                solve(ind+1,ans)
                nums[i],nums[ind] = nums[ind], nums[i]
                    
        ans = []
        solve(0,ans)
        return ans


# s(0) with nums = [1, 2, 3]

# |

# +-- s(1) with nums = [1, 2, 3] (swap 1 with 1 at index 0)

# |   |

# |   +-- s(2) with nums = [1, 2, 3] (swap 2 with 2 at index 1)

# |   |   |

# |   |   +-- s(3) with nums = [1, 2, 3] (swap 3 with 3 at index 2)

# |   |       |

# |   |       +-- ans.append([1, 2, 3]) (base case reached, add to ans)

# |   |   

# |   +-- s(2) with nums = [1, 3, 2] (swap 3 with 2 at index 1)

# |       |

# |       +-- s(3) with nums = [1, 3, 2] (swap 2 with 2 at index 2)

# |           |

# |           +-- ans.append([1, 3, 2]) (base case reached, add to ans)

# |

# +-- s(1) with nums = [2, 1, 3] (swap 2 with 1 at index 0)

# |   |

# |   +-- s(2) with nums = [2, 1, 3] (swap 1 with 1 at index 1)

# |   |   |

# |   |   +-- s(3) with nums = [2, 1, 3] (swap 3 with 3 at index 2)

# |   |       |

# |   |       +-- ans.append([2, 1, 3]) (base case reached, add to ans)

# |   |

# |   +-- s(2) with nums = [2, 3, 1] (swap 3 with 1 at index 1)

# |       |

# |       +-- s(3) with nums = [2, 3, 1] (swap 1 with 1 at index 2)

# |           |

# |           +-- ans.append([2, 3, 1]) (base case reached, add to ans)

# |

# +-- s(1) with nums = [3, 2, 1] (swap 3 with 1 at index 0)

#     |

#     +-- s(2) with nums = [3, 2, 1] (swap 2 with 2 at index 1)

#     |   |

#     |   +-- s(3) with nums = [3, 2, 1] (swap 1 with 1 at index 2)

#     |       |

#     |       +-- ans.append([3, 2, 1]) (base case reached, add to ans)

#     |

#     +-- s(2) with nums = [3, 1, 2] (swap 1 with 2 at index 1)

#         |

#         +-- s(3) with nums = [3, 1, 2] (swap 2 with 2 at index 2)

#             |

#             +-- ans.append([3, 1, 2]) (base case reached, add to ans)