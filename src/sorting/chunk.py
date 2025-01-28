def chunk_radix_sort(a, b, log_counter):
    """Chunk-based radix sorting with initial split by MSB and merge by LSB."""
    max_bits = len(bin(a.size - 1)) - 2  # Maximum number of bits required
    msb_bit = max_bits - 2  # Start chunking with the most significant bits

    # Phase 1: Pass in chunks using MSB (most significant bits)
    for bit in range(msb_bit, max_bits):
        for _ in range(a.size):
            if (a.top.index >> bit) & 1 == 0:
                pb(a, b, log_counter)
            else:
                ra(a, b, log_counter)

    # Phase 2: Return sorted chunks based on LSB (least significant bits)
    for bit in range(msb_bit - 1, -1, -1):
        size = b.size
        while size > 0:
            if (b.top.index >> bit) & 1 == 0:
                pa(a, b, log_counter)
            else:
                rb(a, b, log_counter)
            size -= 1

def compare_chunked_vs_radix(n_elements=100):
    # Create stacks
    a = create_random_stack(n_elements)
    b = Stack()

    # Radix Sort Simulation
    log_radix = LogCounter()
    radix_sort(a, b, log_radix)

    # Reset stacks for Chunked Radix simulation
    a = create_random_stack(n_elements)
    b = Stack()

    # Chunked Radix Sort Simulation
    log_chunked = LogCounter()
    chunk_radix_sort(a, b, log_chunked)

    return log_radix.moves, log_chunked.moves

# Run the comparison and output the results
compare_chunked_vs_radix()
