/**
 * \brief Checks if the container created using default constructor is empty.
 */
BOOST_AUTO_TEST_CASE(testIfEmptyContainerIsCreatedWhenUsingDefaultConstructor)
{
    QueueLimited<int> queue{};
    BOOST_CHECK_EQUAL(queue.empty(), true);
    BOOST_CHECK_EQUAL(queue.size(), 0);
    BOOST_CHECK_EQUAL(queue.full(), false);
}

/**
 * \brief Checks if proper exception is thrown when performing pop() operation
 *        on empty container.
 */
BOOST_AUTO_TEST_CASE(testIfExceptionIsThrownWhenTryingToPopFromEmptyContainer)
{
    QueueLimited<int> queue{};
    BOOST_CHECK_THROW(queue.pop(), QueueLimited<int>::ReadEmptyQueueException)
}
